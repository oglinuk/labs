echo "Building docker image ..."
docker build . -t python-flask-docker

echo "Starting docker container ..."
docker run --name hw-docker-python-flask -p 9001:9001 python-flask-docker