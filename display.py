# Copyright (c) 2023 aivju GmbH
# All rights reserved. Redistribution and use in source and binary forms,
# with or without modification, are not permitted

class BaseDisplay:

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def px(self, x, y, val):
        pass

    def show(self):
        pass

    def clear(self):
        for y in range(self.height):
            for x in range(self.width):
                self.px(x, y, False)