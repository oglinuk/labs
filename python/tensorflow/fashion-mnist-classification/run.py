import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.datasets import fashion_mnist

class ImageClassifier(object):
    def __init__(self):
        self.class_names = ['t-shirt', 'trousers', 'pullover', 'dress', 'coat', 'sandal', 'shirt', 'sneaker', 'bag', 'ankle book']
        (self.train_imgs, self.train_labels), (self.test_imgs, self.test_labels) = fashion_mnist.load_data()
        self.explore_data()
        self.preprocess_data()
        self.model = self.build_model()
        self.train_model()
        self.make_prediction()

    def explore_data(self):
        print(f'\nTraining image shape: {self.train_imgs.shape}')
        print(f'{len(self.train_imgs)} training images')
        print(f'Training Labels: {self.train_labels}')
        print(f'Training labels type: {type(self.train_labels)}')

        print(f'\nTesting image shape: {self.test_imgs.shape}')
        print(f'{len(self.test_imgs)} test images')
        print(f'Test labels: {self.test_labels}')
        print(f'Test labels type: {type(self.test_labels)}')

        plt.figure()
        plt.imshow(self.train_imgs[0])
        plt.colorbar()
        plt.grid(False)
        plt.show()

        plt.figure()
        plt.imshow(self.test_imgs[6])
        plt.colorbar()
        plt.grid(False)
        plt.show()

    def preprocess_data(self):
        self.train_imgs = self.train_imgs / 255
        self.test_imgs = self.test_imgs / 255

        plt.figure(figsize=(10,10))
        for i in range(25):
            plt.subplot(5, 5, i + 1)
            plt.xticks([])
            plt.yticks([])
            plt.grid(False)
            plt.imshow(self.train_imgs[i], cmap=plt.cm.binary)
            plt.xlabel(self.class_names[self.train_labels[i]])
        plt.show()

    def build_model(self):
        model = keras.Sequential([
            keras.layers.Flatten(input_shape=(28, 28)),
            keras.layers.Dense(128, activation='relu'),
            keras.layers.Dense(10)
        ])
        model.compile(
            optimizer='adam',
            loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
            metrics=['accuracy']
        )

        return model

    def train_model(self):
        self.model.fit(
            self.train_imgs, 
            self.train_labels, 
            epochs=10
        )
        
        test_loss, test_acc = self.model.evaluate(self.test_imgs, self.test_labels, verbose=2)
        print(f'Test loss: {test_loss}')
        print(f'Test accuracy: {test_acc}')

    def plot_image(self, prediction, actual_label, img):
        plt.grid(False)
        plt.xticks([])
        plt.yticks([])

        plt.imshow(img, cmap=plt.cm.binary)

        predicted_label = np.argmax(prediction)
        if predicted_label == actual_label:
            color = 'blue'
        else:
            color = 'red'

        predicted_class = self.class_names[predicted_label]
        predicted_percent = 100*np.max(prediction)
        actual_class = self.class_names[actual_label]

        plt.xlabel(f'{predicted_class} {predicted_percent :2.0f}% ({actual_class})', color=color)

    def plot_value_array(self, prediction, actual_label):
        plt.grid(False)
        plt.xticks(range(10))
        plt.yticks([])
        thisplot = plt.bar(range(10), prediction, color="#777777")
        plt.ylim([0, 1])
        predicted_label = np.argmax(prediction)

        thisplot[predicted_label].set_color('red')
        thisplot[actual_label].set_color('blue')


    def make_prediction(self):
        probability_model = keras.Sequential([
            self.model,
            keras.layers.Softmax()
        ])

        probability_model.summary()

        predictions = probability_model.predict(self.test_imgs)

        num_rows = 5
        num_cols = 3
        num_images = num_rows*num_cols
        plt.figure(figsize=(2*2*num_cols, 2*num_rows))
        for i in range(num_images):
            prediction, actual_label, img = predictions[i], self.test_labels[i], self.test_imgs[i]
            plt.subplot(num_rows, 2*num_cols, 2*i+1)
            self.plot_image(prediction, actual_label, img)
            plt.subplot(num_rows, 2*num_cols, 2*i+2)
            self.plot_value_array(prediction, actual_label)
        plt.tight_layout()
        plt.show()



if __name__ == '__main__':
    ImageClassifier()