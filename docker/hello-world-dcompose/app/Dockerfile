FROM python:3.4-alpine
ADD . /helloworld
WORKDIR /helloworld
RUN pip install -r requirements.txt
EXPOSE 9001
CMD ["python", "app.py"]