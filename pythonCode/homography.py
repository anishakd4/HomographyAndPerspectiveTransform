import cv2
import numpy as np

book1 = cv2.imread("../assets/book1.jpg")
book2 = cv2.imread("../assets/book2.jpg")

book1Points = np.array([[650, 1326], [2113, 1333], [2159, 3680], [578, 3680]])
book2Points = np.array([[1456, 1580], [2237, 2048], [1417, 3668], [604, 2750]])

homographyMat1, status1 = cv2.findHomography(book1Points, book2Points)
homographyMat2, status2 = cv2.findHomography(book2Points, book1Points)

result1 = cv2.warpPerspective(book1, homographyMat1, (book2.shape[1], book2.shape[0]))
result2 = cv2.warpPerspective(book2, homographyMat2, (book1.shape[1], book1.shape[0]))

cv2.namedWindow("book1", cv2.WINDOW_NORMAL)
cv2.namedWindow("book2", cv2.WINDOW_NORMAL)
cv2.namedWindow("result1", cv2.WINDOW_NORMAL)
cv2.namedWindow("result2", cv2.WINDOW_NORMAL)

cv2.imshow("book1", book1)
cv2.imshow("book2", book2)
cv2.imshow("result1", result1)
cv2.imshow("result2", result2)

cv2.waitKey(0)
cv2.destroyAllWindows()