import json
import os
import requests
from bs4 import BeautifulSoup
import time
from notion_data import *

# 파일 경로
simple_dir = "./simple/"
detail_dir = "./detail/"

simple_url = f"https://api.notion.com/v1/databases/{id}/query"

HEADER = {
    "Authorization" : f"Bearer {token}"
    "Notion-Version": f"{version}"
}

QUERY_DATA = {
    "filter": {
        "and": [
            {
                "property": "WebPost",
                "checkbox": {
                    "equals": true
                }
            }
        ]
    }
}

def get_pjt_list():
    try:
        res = requests.post(simple_url,json=QUERY_DATA, headers=HEADER)
        res.raise_for_status()

        data = res.json()

        pjt_list = []
        for element in data.get("results", []):
            stack_list = [
                e["name"] for e in element["properties"].get("기술스택", {}).get("multi_select",[])
            ]

            project = {
                "id" : element["id"],
                "lastUpdate": element["last_edited_time"],
                "title": element["properties"].get("Name", {}).get("title", [{}])[0].get("plain_text", ""),
                "summary": element["properties"].get("프로젝트 개요", {}).get("rich_text", [{}])[0].get("plain_text", ""),
                "team": element["properties"].get("인원", {}).get("number"),
                "stacks": stack_list,
                "period": element["properties"].get("기간", {}).get("date"),
            }
            pjt_list.append(project)
        
        print(pjt_list)
        return pjt_list
    
    except requests.exceptions.RequestException as err:
        print("err occuerd : ", err)
        return []

if __name__ == "__main__":
    get_pjt_list