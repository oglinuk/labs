echo "Building first_stage docker image ..."
docker build ./first_stage -t base-cpp-docker:0.1.0

echo
echo "Building second_stage docker image ..."
docker build ./second_stage -t cpp-docker:1.0.0

echo
echo "Starting docker container ..."
docker run -t cpp-docker:1.0.0

