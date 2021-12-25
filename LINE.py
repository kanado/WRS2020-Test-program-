import requests
def line(Me):
    line_notify_token = '#先程発行したコードを貼ります'
    line_notify_api = 'https://notify-api.line.me/api/notify'
    message = '\n' + Me 
    #変数messageに文字列をいれて送信します トークン名の隣に文字が来てしまうので最初に改行しました
    payload = {'message': message}
    headers = {'Authorization': 'Bearer ' + line_notify_token}
    line_notify = requests.post(line_notify_api, data=payload, headers=headers)
