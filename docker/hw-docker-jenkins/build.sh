echo "Starting Jenkins container ..."

docker run -d --name hw_docker_jenkins -p 8080:8080 -p 50000:50000 jenkins/jenkins:lts

echo "Sleeping for 12 seconds while Jenkins spins up. Enter the following password at http://localhost:8080 ..."
sleep 12

docker container exec hw_docker_jenkins cat /var/jenkins_home/secrets/initialAdminPassword
