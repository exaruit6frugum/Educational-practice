import cv2
import numpy as np

image = cv2.imread("test2.jpg")
if image is None:
    print("Ошибка: изображение не загружено")
    exit()

cv2.imshow("Original", image)
cv2.waitKey(0)

blurred = cv2.GaussianBlur(image, (11, 11), 0)
cv2.imshow("Blurred image", blurred)
cv2.waitKey(0)

hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)
cv2.imshow("HSV", hsv)
cv2.waitKey(0)

lower_bound = np.array([0, 50, 50])
upper_bound = np.array([179, 255, 255])

mask = cv2.inRange(hsv, lower_bound, upper_bound)
cv2.imshow("Mask", mask)
cv2.waitKey(0)

contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

if not contours:
    print("Контуры не найдены")
else:
    largest_contour = max(contours, key=cv2.contourArea)

    x, y, w, h = cv2.boundingRect(largest_contour)

    center_x = x + w // 2
    center_y = y + h // 2

    cv2.rectangle(image, (x, y), (x + w, y + h), (0, 0, 255), 3)

    cv2.circle(image, (center_x, center_y), 10, (0, 0, 255), -1)

    cv2.imshow("Largest Object", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()