from flask import Flask, redirect, url_for, request
import requests
import json


app = Flask(__name__)
url_rand = requests.get("http://localhost:8090/rand")
url_prime = requests.get("http://localhost:8090/primes")
url_fibo = requests.get("http://localhost:8090/fibo")
url_odd = requests.get("http://localhost:8090/odd")
main_list = []
json_list = {}

    
@app.route('/numbers',methods = ['GET'])
def post_func():
    rand_json = json.loads(url_rand.text)
    rand = rand_json['numbers']
    prime_json = json.loads(url_prime.text)
    prime = prime_json['numbers']
    odd_json = json.loads(url_odd.text)
    odd = odd_json['numbers']
    fibo_json = json.loads(url_fibo.text)
    fibo = fibo_json['numbers']
        
    main_list.extend(rand)
    main_list.extend(prime)
    main_list.extend(odd)
    main_list.extend(fibo)
    
   
    list_set = set(main_list)
    unique_list = (list(list_set))
    unique_list.sort()
    json_list['numbers'] = unique_list
    return json_list

if __name__ == '__main__':
   app.run(debug = True)