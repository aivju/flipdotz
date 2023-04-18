# Copyright (c) 2023 aivju GmbH
# All rights reserved. Redistribution and use in source and binary forms,
# with or without modification, are not permitted

from flip_dotz_simulator import FlipDotzSimulator

if __name__ == "__main__":
    display = FlipDotzSimulator(width=84, height=48, fps=15)

    for x in range(display.width):
        for y in range(display.height):
            display.px(x, y, 1)
        display.show()
