import cv2
import numpy as np

def main():
    cap = cv2.VideoCapture(0)

    while (True):
        # Capture frames
        _, frame = cap.read()

        # Convert frame color to grayscale
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Display the video
        cv2.imshow('Video', gray)

        # Wait for the q key to be pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the capture
    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()