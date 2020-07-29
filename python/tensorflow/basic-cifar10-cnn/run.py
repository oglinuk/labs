import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import datasets, layers, models

class CifarCNN(object):
    def __init__(self, epochs):
        self.epochs = epochs
        self.classes = ['airplane', 'automobile', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']        
        (self.train_imgs, self.train_labels), (self.test_imgs, self.test_labels) = datasets.cifar10.load_data()
        self.explore_data()
        self.preprocess_data()
        self.model = self.build_model()
        self.history = self.train_model()
        self.evaluate_model()
        self.make_prediction()

    def explore_data(self):
        print(f'\n{len(self.train_imgs)} training examples ...')
        print(f'Train image shape: {self.train_imgs[0].shape}')
        print(f'Train labels: {self.train_labels}')
        print(f'Training labels type: {type(self.train_labels)}')

        print(f'\n{len(self.test_imgs)} test examples ...')
        print(f'Test image shape: {self.test_imgs[0].shape}')
        print(f'Test labels: {self.test_labels}')
        print(f'Test labels type: {type(self.test_labels)}')

        plt.figure(figsize=(10, 10))
        for i in range(25):
            plt.subplot(5, 5, i+1)
            plt.xticks([])
            plt.yticks([])
            plt.grid(False)
            plt.imshow(self.train_imgs[i], cmap=plt.cm.binary)
            plt.xlabel(self.classes[self.train_labels[i][0]])
        plt.show()

    def preprocess_data(self):
        self.train_imgs = self.train_imgs / 255.0
        self.test_imgs = self.test_imgs / 255.0

        plt.figure()
        plt.title(f'{self.classes[self.train_labels[0][0]]} ({self.train_labels[0][0]})')
        plt.imshow(self.train_imgs[0])
        plt.colorbar()
        plt.grid(False)
        plt.show()

    def build_model(self):
        model = models.Sequential([
            layers.Conv2D(32, (3, 3), activation='relu', input_shape=(32, 32, 3)),
            layers.MaxPool2D((2, 2)),
            layers.Conv2D(64, (3, 3), activation='relu'),
            layers.MaxPool2D((2, 2)),
            layers.Conv2D(64, (3, 3), activation='relu'),
            layers.Flatten(),
            layers.Dense(64, activation='relu'),
            layers.Dense(10)
        ])

        model.summary()

        model.compile(
            optimizer='adam',
            loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
            metrics=['accuracy']
        )

        return model

    def train_model(self):
        return self.model.fit(
            self.train_imgs,
            self.train_labels,
            epochs=self.epochs,
            validation_data=(self.test_imgs, self.test_labels)
        )

    def evaluate_model(self):
        test_loss, test_acc = self.model.evaluate(self.test_imgs, self.test_labels, verbose=2)
        print(f'Loss: {test_loss}')
        print(f'Accuracy: {test_acc}')

        plt.plot(self.history.history['accuracy'], label='accuracy')
        plt.plot(self.history.history['val_accuracy'], label='val_accuracy')
        plt.xlabel('Epoch')
        plt.ylabel('Accuracy')
        plt.ylim([0.5, 1])
        plt.legend(loc='lower right')
        plt.show()
    
    def plot_img(self, prediction, actual_label, img):
        plt.grid(False)
        plt.xticks([])
        plt.yticks([])

        plt.imshow(img, cmap=plt.cm.binary)

        predicted_label = np.argmax(prediction)
        if predicted_label == actual_label:
            color = 'blue'
        else:
            color = 'red'

        predicted_class = self.classes[predicted_label]
        confidence = 100*np.max(prediction)
        actual_class = self.classes[actual_label]

        plt.xlabel(f'{predicted_class} {confidence :2.0f}% ({actual_class})', color=color)

    def plot_predictions(self, prediction, actual_label):
        plt.grid(False)
        plt.xticks(range(10))
        plt.yticks([])
        thisplot = plt.bar(range(10), prediction, color="#777777")
        plt.ylim([0, 1])
        predicted_label = np.argmax(prediction)

        thisplot[predicted_label].set_color('red')
        thisplot[actual_label].set_color('blue')

    def make_prediction(self):
        prob_model = keras.Sequential([
            self.model,
            layers.Softmax()
        ])

        predictions = prob_model.predict(self.test_imgs)

        num_rows = 5
        num_cols = 3
        num_images = num_rows*num_cols
        plt.figure(figsize=(2*2*num_cols, 2*num_rows))
        for i in range(num_images):
            plt.subplot(num_rows, 2*num_cols, 2*i+1)
            prediction, actual_label, img = predictions[i], self.test_labels[i][0], self.test_imgs[i]
            self.plot_img(prediction, actual_label, img)
            plt.subplot(num_rows, 2*num_cols, 2*i+2)
            self.plot_predictions(prediction, actual_label)
        plt.tight_layout()
        plt.show()

if __name__ == "__main__":
    CifarCNN(10)