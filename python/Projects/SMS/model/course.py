class Course:
    def __init__(self, id='', name='', description=''):
        self.id = id
        self.name = name
        self.desc = description

    def get_id(self):
        return self.id

    def set_id(self, id):
        self.id = id

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.id = name

    def get_desc(self):
        return self.desc

    def set_desc(self, desc):
        self.id = desc
