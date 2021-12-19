export VIDEOPATH='/Users/joeslie/Movies/Dashcam/road.mp4'
export MODELPATH='/Users/joeslie/Model/openpilot/'
mkdir -p build
cd build
cmake .. 
make
./dmonitoring
