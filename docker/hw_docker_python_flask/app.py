from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello():
	return 'Hello world from python flask in docker!'

if __name__ == '__main__':
	app.run(host='0.0.0.0', port=9001, debug=True)
