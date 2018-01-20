'''
Example of using smtplib to send an email with an attachment
'''
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

# NOTE: You need to 'allow less secure apps on the gmail account'

server = smtplib.SMTP('smtp.gmail.com', 587) # Using Google's smtp.gmail server
server.ehlo() # Handshake of sorts - can be helo() or ehlo()
server.starttls() # encrypts the following statements

msg = MIMEMultipart()
msg['From'] = 'SENDER EMAIL HERE'
msg['To'] = 'RECIEVER EMAIL HERE'
msg['Subject'] = 'Hello world w/ smtplib and email.MIMEMultipart'
body = 'Hello World again!'
msg.attach(MIMEText(body, 'plain')) # this can be changed to html to include different tags like <a href=''>

f = 'wordList.txt'
filename = f.split('.')[0]
attachment = open(f, 'rb')

part = MIMEBase('application', 'octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', 'attachment; filename=%s' % filename)

filename2 = 'Example File 2'
attachment2 = open('Dm_Excercise.txt', 'rb+')

part2 = MIMEBase('application', 'octet-stream')
part2.set_payload((attachment2).read())
encoders.encode_base64(part2)
part2.add_header('Content-Disposition', 'attachment; filename=%s' % filename2)

msg.attach(part)
msg.attach(part2)

server.login(msg['From'], 'PASSWORD HERE') # Logging into the email account that will be sending the mail
server.sendmail(msg['From'], msg['To'], msg.as_string()) # Actually sending the mail [logged in acc] [recipient] [msg]
server.close()
