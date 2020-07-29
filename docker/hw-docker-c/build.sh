echo "Building docker image ..."
docker build . -t c-docker

echo "Starting docker container ..."
docker run c-docker