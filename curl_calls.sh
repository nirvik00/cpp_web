#!/bin/sh


echo "\nbash scripts:\n"

curl http://localhost:8000/hello

echo "\n"

curl -X GET \
  -H "Content-type: application/json" \
  -H "Accept: application/json" \
  -d '{"statusCode": 1024, "message": "Hello DTO!"}' \
  "http://localhost:8000"


echo "\n"