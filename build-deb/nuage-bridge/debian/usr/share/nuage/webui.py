#!/usr/bin/python


# This file is part of NuageWebUI - a port of YunWebUI to Debian 
#
# NuageWebUI is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#
# As a special exception, you may use this file as part of a free software
# library without restriction.  Specifically, if other files instantiate
# templates or use macros or inline functions from this file, or you compile
# this file and link it with other files to produce an executable, this
# file does not by itself cause the resulting executable to be covered by
# the GNU General Public License.  This exception does not however
# invalidate any other reasons why the executable file might be covered by
# the GNU General Public License.
#
# Copyright 2015 Mattias Schlenker (http://www.mattiasschlenker.de/)

# Configuration file /etc/nuage/nuage.cfg
# [RestAPI]
# port=80
# open=True
#
# [Bridge]
# baudrate=19200
# board=ProMini16
# reset=18

import time
import sys
import os
import ConfigParser
from flask import Flask, request, redirect, url_for, send_from_directory
sys.path.insert(0, '/usr/lib/python2.7/bridge/')
from bridgeclient import BridgeClient as bridgeclient

# Create a proper path:
staticroot = os.path.join(os.path.dirname(os.path.abspath(__file__)), "static")
parser = ConfigParser.ConfigParser()
cfg = parser.read("/etc/nuage/nuage.cfg")

app = Flask(__name__, static_url_path='/static', static_folder=staticroot)
brg = bridgeclient()

@app.route('/')
def default_route():
	return "Hello World!"

@app.route('/keystore_manager_example/<path:path>', methods=['GET'])
def send_example(path):
	return send_from_directory(staticroot + '/keystore_manager_example', path)

@app.route('/keystore_manager_example/')
def keystore_index():
	return app.send_static_file('keystore_manager_example/index.html')

@app.route('/data/get/<key>')
def bridge_get_bykey(key):
        res = brg.get(key)
        msg = '{"value":"' + res + '","key":"' + key + '","response":"get"}'
        return msg, 200, {'Content-Type': 'application/json; charset=utf-8'}

@app.route('/data/get/')
def bridge_get_all():
        res = brg.getall()
        arr = []
        for k, v in res.iteritems():
                arr.append('"' + k + '":"' + v + '"')
        msg = '{"value":{' + ','.join(arr) + '},"response":"get"}'
        return msg, 200, {'Content-Type': 'application/json; charset=utf-8'}

@app.route('/data/')
def data_redirect():
	return redirect(url_for('data/get/'))

@app.route('/data/delete/<key>')
def bridge_delete_bykey(key):
        res = brg.delete(key)
        msg = '{"value":"' + res + '","key":"' + key + '","response":"delete"}'
        return msg, 200, {'Content-Type': 'application/json; charset=utf-8'}

@app.route('/data/put/<key>/<val>')
def bridge_put(key, val):
        res = brg.put(key, val)
        msg = '{"value":"' + val + '","key":"' + key + '","response":"put"}'
        return msg, 200, {'Content-Type': 'application/json; charset=utf-8'}

if __name__ == "__main__":
        app.run(host='0.0.0.0',port=int(parser.get("RestAPI", "port")))

