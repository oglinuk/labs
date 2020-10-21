FROM python:3.6-alpine
ADD . /code
WORKDIR /code
RUN pip install -r requirements.txt
EXPOSE 9001
CMD ["python", "app.py"]
