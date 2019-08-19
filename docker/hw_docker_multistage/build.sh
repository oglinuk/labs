echo "Building first_stage docker image ..."
sudo docker build ./first_stage -t base-cpp-docker:0.1.0

echo
echo "Building second_stage docker image ..."
sudo docker build ./second_stage -t cpp-docker:1.0.0

echo
echo "Starting docker container ..."
sudo docker run -t cpp-docker:1.0.0

