import random


def load(filename="ns224k-ORIGIN.txt"):
    with open(filename) as f:
        lines = f.readlines()
    return lines


def gen_unique_ip(ips):
    while True:
        ip = random.randint(1, 2**29-1)
        if ip not in ips:
            ips.add(ip)
            break
    # while
    return ip


def process(lines):
    ips = set()
    lines_with_ip = ["{} {}".format(line.strip(), gen_unique_ip(ips)) for line in lines]
    return lines_with_ip


def save(lines, filename="ns224k.txt"):
    with open(filename, "w+") as f:
        for line in lines:
            f.write("{}\n".format(line))


if __name__ == "__main__":
    lines = process(load())
    cfg = [(20000, "ns20k.txt"),
           (40000, "ns40k.txt"),
           (80000, "ns80k.txt"),
           (160000, "ns160k.txt"),
           (250000, "ns224k.txt")]
    for total, filename in cfg:
        save(lines[:total], filename)