import requests
import openpyxl
import json
import base64
from flask import (
    Flask,
    redirect,
    render_template,
    request,
    send_from_directory,
    jsonify,
    make_response,
    session,
    flash,
    url_for,
)
import pandas as pd
import excel
import re
import utilityFunctions as func
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
#from jira.client import JIRA
import sqlite3
import random
from functools import wraps
app = Flask(__name__)



@app.route("/view-features-TJ1600_R7_0_0_0", methods=["GET"])
def viewFeatureTJ1600_R7_0_0_0():
    # Define the maps for category and project
    category_map = {
        "Sys-OAM": 2,
        "Platform": 3,
        "OTN": 4,
        "DIGI": 5,
        "L2": 6,
        "Control Plane": 7,
        "DWDM": 8,
        "System": 9,
    }

    project_map = {
        "TJ1600": 0,
        "TJ1900": 2,
        "TJ1900_R2.1": 6,
        "TJ1600_R6.3.0": 7,
        "Other": 3,
    }

    cred = "Basic " + base64.b64encode(
        b"emailid:api token"
    ).decode("utf-8")

    headers = {
        "Accept": "application/json",
        "Content-Type": "application/json",
        "Authorization": cred,
    }

    projectKey = "TJ1600"
    jql = "project=" + projectKey + " AND issuetype=Epic"
    url = "https://any/rest/api/3/search?jql=" + jql

    response = requests.request("GET", url, headers=headers)

    json_data = json.loads(response.content.decode("utf-8", "ignore"))

    if "issues" not in json_data:
        print("Error: unexpected response structure")
    else:
        rows = ""
        epic_seq_num = 1
        issues_sorted = sorted(json_data["issues"], key=lambda x: float(x["fields"]["customfield_10040"]) if x["fields"]["customfield_10040"] is not None else 9999)

        # Assign a sequential number to each issue based on the sorted order
        for index, item in enumerate(issues_sorted):
            key = item["key"]
            summary = item["fields"]["summary"]
            project_name = item["fields"]["project"]["name"]
            status = item["fields"]["status"]["name"]
            assignee = (
                item["fields"]["assignee"]["displayName"]
                if item["fields"]["assignee"]
                else "Unassigned"
            )

    # Write the HTML table to a file
    with open("/var/www/webServer/templates/r62output.html", "w", encoding="utf-8") as f:
        f.write(content + js_code)
    response = make_response(render_template("r62output.html"))
    response.headers["Cache-Control"] = "public, max-age=3600"  # Set cache-control header
    return response
