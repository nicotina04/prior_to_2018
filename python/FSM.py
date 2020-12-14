class State():
    def __init__(self, string):
        self.regex = string

    def on_event(self, event, idx):
        pass

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        return self.__class__.__name__

class Start(State):
    def on_event(self, event, idx):
        if event[idx] == 'x':
            return Xexist(event)
        elif event[idx] == 'y':
            return IsY(event)
        else:
            return Notmatch(event)

class Xexist(State):
    def on_event(self, event, idx):
        if event[idx] == 'x':
            return Xexist(event)
        elif event[idx] == 'y':
            return IsY(event)
        else:
            return Notmatch(event)


class Aexist(State):
    def on_event(self, event, idx):
        if event[idx] == 'a':
            return Aexist(event)
        elif event[idx] == 'b':
            return IsB(event)
        else:
            return Notmatch(event)

class IsY(State):
    def on_event(self, event, idx):
        if event[idx] == 'a':
            return Aexist(event)
        elif event[idx] == 'b':
            return IsB(event)
        else:
            return Notmatch(event)

class IsB(State):
    def on_event(self, event, idx):
        return Match(event)

class NoXbutA(State):
    pass

class NoAbutX(State):
    pass

class Notmatch(State):
    def on_event(self, event, idx):
        return Notmatch(event)

class Match(State):
    def on_event(self, event, idx):
        return Match(event)

class simpleregex():
    def __init__(self, string):
        self.rex = string
        self.state = Start(string)
        self.idx = 0

    def on_event(self, event):
        self.state = self.state.on_event(event, self.idx)
        self.idx += 1

def solution(reg):
    victim = simpleregex(reg)
    while victim.idx < len(reg):
        victim.on_event(reg)

    if str(victim.state) == 'IsB':
        return 1
    else:
        return 0




if __name__ == '__main__':
    print(solution('xxya'))
    print(solution('xyaab'))
    print(solution('xyb'))
    print(solution('xab'))
