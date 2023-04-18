# Copyright (c) 2023 aivju GmbH
# All rights reserved. Redistribution and use in source and binary forms,
# with or without modification, are not permitted

from sys import exit
import pygame as pg
from display import BaseDisplay

PX_DIM = 15  # Pixel dimensions in display
YDOT_FILE = "assets/ydot.jpg"
BDOT_FILE = "assets/bdot.jpg"


class FlipDotzSimulator(BaseDisplay):

    def __init__(self, width, height, fps):
        super().__init__(width, height)
        pg.init()
        pg.display.set_caption("FlipDotzSimulator")
        self.screen = pg.display.set_mode(
            (self.width * PX_DIM, self.height * PX_DIM)
        )
        self.y = pg.image.load(YDOT_FILE).convert()
        self.b = pg.image.load(BDOT_FILE).convert()
        self.clock = pg.time.Clock()
        self.fps = fps
        self.clear()

    def set(self, x, y):
        self.screen.blit(self.y, (x * PX_DIM, y * PX_DIM))

    def reset(self, x, y):
        self.screen.blit(self.b, (x * PX_DIM, y * PX_DIM))

    def px(self, x, y, val):
        if val:
            self.set(x, y)
        else:
            self.reset(x, y)

    def show(self):
        for event in pg.event.get():
            if event.type == pg.QUIT:
                exit(0)

        pg.display.flip()
        self.clock.tick(self.fps)

    def clear(self, invert=False):
        for y in range(self.height):
            for x in range(self.width):
                if invert:
                    self.set(x, y)
                else:
                    self.reset(x, y)

    def close(self):
        pg.quit()
