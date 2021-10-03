from collections import deque


class LRUCache(object):
    """
    Implement of LRUCache based on dict and deque in CPython
    """

    def __init__(self, capacity: int = 3):
        self.map = dict()
        self.dll = deque()
        self.cap = capacity

    def set(self, key: str, value: str) -> bool:
        """
        set a pair of <key: value> in deque and dict.

        Parameters:
        -----------
        key: str
        value: str

        Returns:
        --------
        boolean -> True/False
        """
        try:
            if(key in self.map.keys()):
                self._set_first(key, value)
                self.map[key] = value
                return True
            else:
                if(len(self.dll) >= self.cap):
                    self._rm_lru()
                self.dll.appendleft(value)
                self.map[key] = value
                return True
        except:
            assert "KEY INSERTION ERROR!"
            return False

    def get(self, key: str) -> str:
        """
        search key in LRUCache, if found,
        return the key's value, or return False.

        Parameters:
        -----------
        key: str

        Returns:
        --------
        self.map[key]: str
        /
        boolean -> Flase
        """
        if(key in self.map.keys()):
            self._set_first(key)
            return self.map[key]
        else:
            return False

    def display(self):
        print(self.map, self.dll)

    def _set_first(self, key: str, sub: str = None) -> None:
        value = self.map[key]
        self.dll.remove(value)
        if(not sub):
            self.dll.appendleft(value)
        else:
            self.dll.appendleft(sub)

    def _rm_lru(self) -> None:
        self.dll.pop()


if __name__ == "__main__":
    lru_cache = LRUCache()

    print(lru_cache.set("Bill Gatez", "Fool")
          lru_cache.set("Jacklanda", "Noob")
          lru_cache.set("Elon Musk", "Dummy"))

    print(lru_cache.get("Bill Gatez")
          lru_cache.get("Jacklanda")
          lru_cache.get("Elon Musk"))
