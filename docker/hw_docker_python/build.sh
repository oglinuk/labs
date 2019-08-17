echo "Building docker image ..."
sudo docker build . -t python-docker

echo "Starting docker container ..."
sudo docker run python-docker