import cv2
import pytesseract
import os
from PIL import Image
import sys
import numpy as np




def get_string():
    # Read image with opencv
    """camera = cv2.VideoCapture(0)
    return_value, image = camera.read()
    cv2.imwrite('testing.jpg', image)
    """
    img = cv2.imread('tesstt.png')

    # Convert to gray
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Apply dilation and erosion to remove some noise
    kernel = np.ones((1, 1), np.uint8)
    img = cv2.dilate(img, kernel, iterations=1)
    img = cv2.erode(img, kernel, iterations=1)

    # Write the image after apply opencv to do some ...
    cv2.imwrite("thres.png", img)
    # Recognize text with tesseract for python
    result = pytesseract.image_to_string(Image.open("thres.png"))
    os.remove("thres.png")

    return result

if __name__ == '__main__':
    from sys import argv

    print('--- Start recognize text from image ---')
    for i in range(1):
        print(argv[i])
        print(get_string())
        print()
        print()

    print('------ Done -------')
