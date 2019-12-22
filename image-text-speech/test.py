import cv2
import pytesseract
camera = cv2.VideoCapture(0)
return_value, image = camera.read()
cv2.imwrite('testing.jpg', image)
img = cv2.imread('testing.jpg')
text = pytesseract.image_to_string(img)
print(text)
cv2.imshow("Frame", image)
cv2.waitKey(0)
