
with open("teste.js",'r') as arq:
    result = arq.read()

result = result.replace("(",': [')
result = result.replace(")",']')

with open("result.yaml",'w') as arq:
    arq.write(result)