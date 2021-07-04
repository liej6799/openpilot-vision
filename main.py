import cv2
import numpy

cap = cv2.VideoCapture("/data/Videos/f.mp4")
if not cap.isOpened():
    print("Error open video file")

while (cap.isOpened()):
    ret, frame = cap.read()
    if ret:
        cv2.imshow('frame', frame);
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    else:
        break
cap.release()
cv2.destroyAllWindows()


