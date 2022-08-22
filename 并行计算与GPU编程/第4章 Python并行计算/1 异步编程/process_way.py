import socket
from concurrent import futures

import time

def blocking_way():
    sock = socket.socket()
    # blocking
    sock.connect(('baidu.com', 80))
    request = 'GET / HTTP/1.0\r\nHost: baidu.com\r\n\r\n'
    sock.send(request.encode('ascii'))
    response = b''
    chunk = sock.recv(4096)
    while chunk:
        response += chunk
        # blocking
        chunk = sock.recv(4096)
    return response



def process_way():
    workers = 10
    with futures.ProcessPoolExecutor(workers) as executor:
        futs = {executor.submit(blocking_way) for i in range(10)}
    return len([fut.result() for fut in futs])


if __name__ == "__main__": 
    import time
    start = time.time()
    print(process_way())
    print(time.time() - start)