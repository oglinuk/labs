import sys
from app import app
from flask import render_template, jsonify, abort

languages = [
    {
        'id': 1,
        'title': u'Python',
        'description': u'Python is an interpreted high-level programming language for general-purpose programming.',
        'TIOBE index': 4
    },
    {
        'id': 2,
        'title': 'Go',
        'description': 'Go (often referred to as golang) is a programming language that is a compiled, statically typed language in the tradition of Algol and C, with garbage collection, limited structural typing, memory safety features and CSP-style concurrent programming features added',
        'TIOBE index': 19
    }
]

##### ROUTE HANDLERS #####

@app.route('/')
def serveDefault():
    try:
        return render_template('/index.html')
    except Exception as e:
        print(str(e))
        return render_template('/404.html', error='{} - Error is near line {}'.format(str(e), (sys.exc_info()[-1].tb_lineno)))

##### API ROUTES #####

# ../languages -> yields json of every entry(languages)
@app.route('/api/v1.0/languages', methods=['GET'])
def serveLanguages():
    return jsonify({'languages': languages})

# ../languages/[id] || [title] -> yields json of the specified entry(language)
@app.route('/api/v1.0/languages/<int:language_id>', methods=['GET'])
def get_languages(language_id):
    language = [lang for lang in languages if lang['id'] == language_id]
    if len(language) == 0:
        abort(404)
    return jsonify({'language': language[0]})

# Error Handler
@app.errorhandler(404)
def serve_error(error):
    return make_response(jsonify({'error':'Something has gone terribly wrong'}), 404)
