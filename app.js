var express = require("express");
var app = express();
var fs = require("fs");
const { request } = require("http");

var publicDir = require("path").join(__dirname, "/public");
app.use(express.static(publicDir));

var bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({ extended: false }));

const session = require("express-session");
app.use(
  session({
    resave: true,
    saveUninitialized: true,
    secret: "somesecret",
    cookie: { maxAge: 60000 },
  })
);

// npm i handlebars consolidate --save
const engines = require("consolidate");
app.engine("hbs", engines.handlebars);
app.set("views", "./views");
app.set("view engine", "hbs");

//localhost:5000
app.get("/", function (req, res) {
  let currentDate = new Date();
  res.render("index", { model: currentDate, user: req.session.user });
});

app.get("/login", (req, res) => {
  res.render("login");
});

app.post("/doLogin", (req, res) => {
  let name = req.body.txtName;
  if (name == "tom") {
    req.session.user = {
      name: name,
      role: "name",
    };
  } else {
    req.session.user = {
      name: name,
      role: "guest",
    };
  }
  res.redirect("/");
});

app.get("/register", (req, res) => {
  res.render("register");
});

var fileName = "Users.txt";
app.post("/doRegister", (req, res) => {
  let inputID = req.body.userID;
  let inputName = req.body.username;
  let pass = req.body.pass;
  //check data before writing to file
  if (inputID.length < 4) {
    let errorModel = { errorMsg: "Ten phai lon hon 3 ky tu!" }; //neu them canhr baos thif ghi ","
    res.render("register", { model: errorModel });
  } else {
    let data = `${inputID} ; ${inputName} ; ${pass} `;
    fs.appendFile(fileName, data, (err) => {
      res.redirect("/");
    });
  }
});

app.get("/allUsers", (req, res) => {
  let result = [];
  fs.readFile(fileName, "utf8", (err, data) => {
    let allNames = data.split("\n");
    for (i = 0; i < allNames.length; i++) {
      if (allNames[i].trim().length != 0) {
        let userID = allNames[i].split(";")[0];
        let name = allNames[i].split(";")[1];
        let pass = allNames[i].split(";")[2];
        result.push({ userID: userID, name: name, pass: pass });
      }
    }
    res.render("allUsers", { model: result });
  });
});

app.listen(5000);
