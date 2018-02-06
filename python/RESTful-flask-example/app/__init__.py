import os
from flask import Flask

app = Flask(__name__, instance_relative_config=True)

from app.controller import views

app.config.from_object('config')
app.secret_key = os.urandom(24)
