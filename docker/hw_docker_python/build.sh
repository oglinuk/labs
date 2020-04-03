echo "Building docker image ..."
docker build . -t python-docker

echo "Starting docker container ..."
docker run python-docker