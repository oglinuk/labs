output:
	docker run -d --name hw-docker-jenkins -p 8080:8080 -p 50000:50000 jenkins/jenkins:lts

# Wait 10-15 seconds before running make password to get the jenkins instance password.
password:
	docker container exec hw-docker-jenkins cat /var/jenkins_home/secrets/initialAdminPassword

clean:
	docker stop hw-docker-jenkins
	docker rm hw-docker-jenkins