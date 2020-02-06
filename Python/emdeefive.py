from flask import Flask
from flask import request
import hashlib

app=Flask(__name__)

@app.route('/')
def func():
    return hashlib.md5(request.args.get('data'))

if __name__=='__main__':
    app.run(port=8081,debug=True) 