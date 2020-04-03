echo "Building docker image ..."
docker build . -t go-docker

echo "Starting docker container ..."
docker run go-docker