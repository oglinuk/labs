echo "Building docker image ..."
sudo docker build . -t go-docker-website

echo "Starting docker container ..."
sudo docker run -p 9001:9001 go-docker-website