import smtplib
def email():
    TO = 'datamailmd@gmail.com'
    SUBJECT = 'Data'
    TEXT = str(df)

    # Gmail Sign In
    gmail_sender = 'datamailmd@gmail.com'
    gmail_passwd = 'Jodhpur25'

    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login(gmail_sender, gmail_passwd)

    BODY = '\r\n'.join(['To: %s' % TO,
                        'From: %s' % gmail_sender,
                        'Subject: %s' % SUBJECT,
                        '', TEXT])

    try:
        server.sendmail(gmail_sender, [TO], BODY)
        print ('email sent')
    except:
        print ('error sending mail')

    server.quit()