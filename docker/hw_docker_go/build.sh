echo "Building docker image ..."
sudo docker build . -t go-docker

echo "Starting docker container ..."
sudo docker run go-docker