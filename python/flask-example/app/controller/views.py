from app import app
from flask import render_template, jsonify, abort, make_response, redirect

languages = [
    {
        'id': 1,
        'title': 'Python',
        'description': 'Python is an interpreted high-level programming language for general-purpose programming.',
        'TIOBE index': 4
    },
    {
        'id': 2,
        'title': 'Go',
        'description': 'Go (often referred to as golang) is a programming language that is a compiled, statically typed language in the tradition of Algol and C, with garbage collection, limited structural typing, memory safety features and CSP-style concurrent programming features added',
        'TIOBE index': 17
    },
    {
        'id': 3,
        'title': 'Rust',
        'description': 'Rust is a multi-paradigm systems programming language focused on safety, especially safe concurrency.',
        'TIOBE index': 35
    }
]

##### ROUTE HANDLERS #####

# / is the base route which redirects to /languages/ 
@app.route('/')
def serve_index():
    return redirect('/languages/')

# /languages -> yields json of every entry(languages)
@app.route('/languages/', methods=['GET'])
def serve_languages():
    return render_template('/index.html', value=languages)

# /languages/[id] -> yields json of the specified entry(language)
@app.route('/languages/<int:language_id>', methods=['GET', 'POST'])
def serve_language_id(language_id):
    language = [lang for lang in languages if lang['id'] == language_id]
    if len(language) == 0:
        abort(404)
    return jsonify({'language': language[0]})

# Error Handler
@app.errorhandler(404)
def serve_error(error):
    return make_response(jsonify({'error':'Something has gone terribly wrong'}), 404)
