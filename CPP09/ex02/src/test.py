from time import time, sleep
from contextlib import contextmanager


time_dict: dict[str, float] = {}


@contextmanager
def time_to_run(context_name: str):
    start = time()
    try:
        yield
    finally:
        end = time()
        elapsed_time = end - start
        time_dict[context_name] = time_dict.get(context_name, 0) + elapsed_time

def print_time_dict():
    for k, v in time_dict.items():
        print(f"{k}: {v:.4f}s")

for i in range(3):
    print("loop", i)
    with time_to_run("time to perform conv"):
        sleep(3)

    with time_to_run("time to perform relu"):
        sleep(1)

    with time_to_run("time to perform softmax"):
        sleep(2)


print_time_dict()