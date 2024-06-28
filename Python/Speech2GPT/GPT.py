from openai import OpenAI
import requests

key = 'Your KEY'

headers={
    "Authorization":f"Bearer {key}"
}

def GPT_TALK(text):
    data={
        "model":"gpt-4",
        "messages":[{"role" : "user",
                     "content" : text}],
        "max_tokens":100,
        "n":2
    }

    res = requests.post("https://api.openai.com/v1/chat/completions", headers=headers, json=data)
    if res.status_code == 200:
        return res.json()["choices"][0]["message"]["content"].strip()

    else:
        return "error"



