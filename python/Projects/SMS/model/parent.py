class Parent:
    def __init__(self, id='', fname='', lname='', pwd='', mobile_num='', phn_num='', email='', dob='', doj='', last_seen=''):
        self.id = id
        self.fname = fname
        self.lname = lname
        self.pwd = pwd
        self.mobile_num = mobile_num
        self.phn_num = phn_num
        self.email = email
        self.dob = dob
        self.doj = doj
        self.last_seen = last_seen

    def get_id(self):
        return self.id

    def set_id(self, id):
        self.id = id

    def get_fname(self):
        return self.fname

    def set_fname(self, fname):
        self.fname = fname

    def get_lname(self):
        return self.lname

    def set_lname(self, lname):
        self.lname = lname

    def get_pwd(self):
        return self.pwd

    def set_pwd(self, pwd):
        self.pwd = pwd

    def get_mobile_num(self):
        return self.mobile_num

    def set_mobile_num(self, mobile_num):
        self.mobile_num = mobile_num

    def get_phn_num(self):
        return self.phn_num

    def set_phn_num(self, phn_num):
        self.phn_num = phn_num

    def get_email(self):
        return self.email

    def set_email(self, email):
        self.email = email

    def get_dob(self):
        return self.dob

    def set_dob(self, dob):
        self.dob = dob

    def get_doj(self):
        return self.doj

    def set_doj(self, doj):
        self.doj = doj

    def get_last_seen(self):
        return self.last_seen

    def set_last_seen(self, last_seen):
        self.last_seen = last_seen
