from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader
import datetime

def index(request):
    home = loader.get_template("home.html")
    text = []
    return HttpResponse(home.render())

def current_datetime(request):
    now = datetime.datetime.now()
    html = f"<html><body>It is now {now}.</body></html>"
    home = 'http://127.0.0.1:8000/'
    return HttpResponse(html + "<a href=" + home + "> return" "</a>")



