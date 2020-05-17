echo "Building docker image ..."
docker build . -t go-docker-website

echo "Starting docker container ..."
docker run -p 9001:9001 go-docker-website