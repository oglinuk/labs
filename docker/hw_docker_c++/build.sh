echo "Building docker image ..."
docker build . -t cpp-docker

echo "Starting docker container ..."
docker run cpp-docker