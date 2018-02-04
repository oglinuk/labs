from flask import Flask

@app.route('/')                     # Handler for URL
def hello_world():
    return 'Hello World!'           # View - what the user sees

if __name__ == '__main__':
    app = Flask(__name__)           # Initializing a Flask app
    app.run(port=7777, debug=True)  # Running the app on localhost:7777
