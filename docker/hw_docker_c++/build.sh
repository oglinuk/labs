echo "Building docker image ..."
sudo docker build . -t cpp-docker

echo "Starting docker container ..."
sudo docker run cpp-docker