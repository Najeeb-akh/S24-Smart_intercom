import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:intl/intl.dart';
import 'package:flutter/services.dart';
import 'dart:async';
import 'auth.dart';
import 'Dashboard.dart';
import 'account.dart';
import 'package:google_fonts/google_fonts.dart';
import 'get_photo_page.dart';

class AppThemes {
  static final ThemeData lightTheme = ThemeData(
    primaryColor: const Color.fromARGB(255, 127, 127, 128),
    primarySwatch: Colors.red,
    secondaryHeaderColor: Colors.amber,
    textTheme: TextTheme(
      headlineLarge: TextStyle(fontSize: 72.0, fontWeight: FontWeight.bold),
      bodyMedium: TextStyle(fontSize: 14.0, fontFamily: 'Hind'),
    ),
    buttonTheme: ButtonThemeData(
      buttonColor: Colors.blue,
      textTheme: ButtonTextTheme.primary,
    ),
  );
}


// setup macro or enum
const int time_for_lock = 8;

int _pass = 0;

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
        return MaterialApp(
      title: 'Flutter Demo',
      home: AuthenticationPage(),
      //GetPhotoPage(), 
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;
  //int _lockValue = 0;
  final DatabaseReference _databaseReference = FirebaseDatabase.instance.ref();
  void _unlockdoor() {
    setState(() {
      _counter++;
      // this code for firebase access lets test it out: 
      _databaseReference.child('lock').set(100);
      // get current epoch time
      //_databaseReference.child('time').set();
      
      // wait for 5 seconds
      Future.delayed(const Duration(seconds: time_for_lock), () {
        _databaseReference.child('lock').set(0);
      });

      // // sanity check for wifi connection
      // if (await checkWifiConnection()) {
        
      //     final snackBar = SnackBar(content: Text('Unlocking Door Remotely!'));
      //     ScaffoldMessenger.of(context).showSnackBar(snackBar);
      //   // code to execute if wifi is connected
      // } else {

      //     final snackBar = SnackBar(content: Text('oops! No Wifi Connection!'));
      //     ScaffoldMessenger.of(context).showSnackBar(snackBar);
 
      //   // code to execute if wifi is not connected
      // }

      // // function to check wifi connection
      // Future<bool> checkWifiConnection() async {
      //   // implement your logic to check wifi connection here
      //   // return true if wifi is connected, false otherwise
      //   // you can use packages like connectivity to check wifi connection status
      //   // example code using connectivity package:
      //   // var connectivityResult = await (Connectivity().checkConnectivity());
      //   // return connectivityResult == ConnectivityResult.wifi;
        
      //   return true; // replace with your actual implementation
      // }

      // this code for in case we want to use big prompt
      // showDialog(
      //         context: context,
      //         builder: (BuildContext context) {
      //           return AlertDialog(
      //             title: Text('Alert'),
      //             content: Text('This is an alert dialog message!'),
      //             actions: <Widget>[
      //               TextButton(
      //                 child: Text('OK'),
      //                 onPressed: () {
      //                   Navigator.of(context).pop();
      //                 },
      //               ),
      //             ],
      //           );

      //         }
      //         );
      
      });
  }

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      appBar: AppBar(
        // TRY THIS: Try changing the color here to a specific color (to
        // Colors.amber, perhaps?) and trigger a hot reload to see the AppBar
        // change color while the other colors stay the same.
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: Text(widget.title),
      ),
      body: Center(
        // Center is a layout widget. It takes a single child and positions it
        // in the middle of the parent.
        child: Column(
          // Column is also a layout widget. It takes a list of children and
          // arranges them vertically. By default, it sizes itself to fit its
          // children horizontally, and tries to be as tall as its parent.
          //
          // Column has various properties to control how it sizes itself and
          // how it positions its children. Here we use mainAxisAlignment to
          // center the children vertically; the main axis here is the vertical
          // axis because Columns are vertical (the cross axis would be
          // horizontal).
          //
          // TRY THIS: Invoke "debug painting" (choose the "Toggle Debug Paint"
          // action in the IDE, or press "p" in the console), to see the
          // wireframe for each widget.
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
             FloatingActionButton(onPressed:(){
              Navigator.push(context, MaterialPageRoute(builder: (context) => AddPasswordPage(title: 'Add Temp Password')));
             },
              tooltip: 'Unlock Door',
              child: const Icon(Icons.add),
              backgroundColor: Color.fromRGBO(185, 193, 185, 1),

            ),
            const Text(
              'You have pushed the button this many times:',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
            FloatingActionButton(onPressed: _unlockdoor,
              tooltip: 'Unlock Door',
              child: const Icon(Icons.lock),
              backgroundColor: Color.fromRGBO(185, 193, 185, 1),

            ),

          ],
        ),
      ),
      // make this button in the middle of the page
    );
  }
}



// start of second page


class AddPasswordPage extends StatefulWidget {
  const AddPasswordPage({super.key, required this.title});

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  State<AddPasswordPage> createState() => _AddPasswordPage();
}


class _AddPasswordPage extends State<AddPasswordPage> {
  late Timer _timer;

  @override
  void initState() {
    super.initState();
    _startTimer();
  }

  void _startTimer() {
    _timer = Timer.periodic(Duration(seconds: 10), (timer) {
      _updateDatabaseReference2();
    });
  }

  void _updateDatabaseReference2() {
    final DatabaseReference _databaseReference2 = FirebaseDatabase.instance.ref('time');
    // save the epoch of current time:
    // i added an aditional 10 seconds to the current time just incase
    _databaseReference2.child('time').set(DateTime.now().millisecondsSinceEpoch + 10000);

  }

  @override
  void dispose() {
    _timer.cancel();
    super.dispose();
  }
  //int _lockValue = 0;
  final DatabaseReference _databaseReference = FirebaseDatabase.instance.ref('tempPass');

   DateTime? _selectedDate;
  TimeOfDay? _selectedTime;
   final TextEditingController _stringController = TextEditingController();
  //final DatabaseReference _databaseReference = FirebaseDatabase.instance.reference().child('pincodes');

  Future<void> _selectDate(BuildContext context) async {
    DateTime now = DateTime.now();
    DateTime initialDate = _selectedDate ?? now;

    DateTime? pickedDate = await showDatePicker(
      context: context,
      initialDate: initialDate,
      firstDate: DateTime(now.year - 5),
      lastDate: DateTime(now.year + 5),
    );

    if (pickedDate != null && pickedDate != _selectedDate) {
      setState(() {
        _selectedDate = pickedDate;
      });
    }
  }

  Future<void> _selectTime(BuildContext context) async {
    TimeOfDay initialTime = _selectedTime ?? TimeOfDay.now();

    TimeOfDay? pickedTime = await showTimePicker(
      context: context,
      initialTime: initialTime,
    );

    if (pickedTime != null && pickedTime != _selectedTime) {
      setState(() {
        _selectedTime = pickedTime;
      });
    }
  }

  void _saveDateTime() {
    if (_selectedDate != null && _selectedTime != null) {
      DateTime selectedDateTime = DateTime(
        _selectedDate!.year,
        _selectedDate!.month,
        _selectedDate!.day,
        _selectedTime!.hour,
        _selectedTime!.minute,
      );

      // Convert to milliseconds since epoch
      int expiryTimestamp = selectedDateTime.millisecondsSinceEpoch;
      if(_pass == 100)
      {
        expiryTimestamp = 2724833187147;

      }
      // Save to Firebase
      _databaseReference.child(_stringController.text).set({
        'code': _stringController.text,
        'expiry': expiryTimestamp,
      });

      // Clear selections
      setState(() {
        _selectedDate = null;
        _selectedTime = null;
      });

      ScaffoldMessenger.of(context).showSnackBar(SnackBar(
        content: Text('Date and time saved!'),
      ));
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        //backgroundColor: Color.fromRGBO(255, 255, 255, 1),
        titleSpacing: 37,
        toolbarHeight: 80,
        title:  Text(
                'Add Passwords',
                style: GoogleFonts.getFont(
                  'Inter',
                  fontWeight: FontWeight.w700,
                  fontSize: 25,
                  height: 1,
                  color: Color(0xFF000000),
                
                ),
                //textAlign: TextAlign.center,
                //overflow: TextOverflow.clip,
              ),
      ),
      body: 
      SingleChildScrollView(
      child: 
      Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
              Text(
                'Valid Temporary Passwords:',
                style: GoogleFonts.getFont(
                  'Inter',
                  fontWeight: FontWeight.w400,
                  fontSize: 20,
                  height: 1,
                  color: Color(0xFF000000),
                
                ),
               
              ),
            
            SizedBox(height: 10),
            Container(
                    margin: EdgeInsets.fromLTRB(20, 0, 20, 20),
                    child: Container(
                      decoration: BoxDecoration(
                        color: Color(0xFFE6E6E6),
                        borderRadius: BorderRadius.circular(40),
                        border: Border.all(
                          color: Color(0xFF000000),
                          width: 1.5,
                        ),
                        
                      ),
                      child: Container(
                        width: 336,
                        height: 285,
                        padding: EdgeInsets.fromLTRB(7, 4, 8, 8),
                        child: Container(
                          decoration: BoxDecoration(
                            borderRadius: BorderRadius.circular(33),
                            //color: Color(0xFF000000),
                            
                          ),
                          child: 
                          Container(
                            height: 250,
                            child: StreamBuilder<DatabaseEvent>(
                              stream: _databaseReference
                                .orderByChild('expiry')
                                .startAt(DateTime.now().millisecondsSinceEpoch)
                                .onValue,
                                builder: (BuildContext context, AsyncSnapshot<DatabaseEvent> snapshot) {
                                if (snapshot.hasData) {
                                  if (snapshot.data!.snapshot.value != null) {
                                    Map<dynamic, dynamic> dataMap = snapshot.data!.snapshot.value as Map<dynamic, dynamic>;
                                    List<dynamic> dataList = dataMap.values.toList();
                                    //List<String> keysList = dataMap.keys.toList();

                                    return ListView.builder(
                                      itemCount: dataList.length,
                                      itemBuilder: (BuildContext context, int index) {
                                        String code = dataList[index]['code'];
                                        //String key = dataList[index];
                                        //String key = keysList[index];
                                        return ListTile(
                                          title: Text(code),
                                          trailing: ElevatedButton(
                                            onPressed: () {
                                              
                                              dataMap.forEach((key, value) {
                                                if (value['code'] == code) {
                                                // show on the screen the key
                                                _databaseReference.child("$key/expiry").set(0);
                                                _databaseReference.child("$key/code").set("-1");
                                                
                                                showDialog(
                                                  context: context,
                                                  builder: (BuildContext context) {
                                                    return AlertDialog(
                                                      title: Text(value['code']),
                                                        content: Text("This password is no longer available"),
                                                      actions: [
                                                        ElevatedButton(
                                                          onPressed: () {
                                                            Navigator.of(context).pop();
                                                          },
                                                          child: Text('Close'),
                                                        ),
                                                      ],
                                                    );
                                                  },
                                                );
                                                

                                                }
                                              });
                                            },
                                            child: Text('Invalidate'),
                                          ),
                                        );
                                      },
                                    );
                                  } else {
                                    return Center(
                                      child: Text('No active codes.'),
                                    );
                                  }
                                } else if (snapshot.hasError) {
                                  return Center(
                                    child: Text('Error: ${snapshot.error}'),
                                  );
                                } else {
                                  return Center(
                                    child: CircularProgressIndicator(),
                                  );
                                }
                              },
                            ),
                          ),

                        ),
                      ),
                    ),
                  ),
            
            SizedBox(height: 20),
            Text(
              _selectedDate != null && _selectedTime != null
                  ? 'Selected Date and Time: ${DateFormat('d MMMM yyyy').format(_selectedDate!)} at ${_selectedTime!.format(context)}'
                  : 'No Date and Time Selected!',
            ),
            // SizedBox(height: 10),
            // ElevatedButton(
            //   onPressed: () => _pass=100,
            //   child: Text('Hard codded pass?'),
            // ),
            SizedBox(height: 10),
            ElevatedButton(
              onPressed: () => _selectDate(context),
              child: Text('Select Date'),
            ),
            SizedBox(height: 10),
            ElevatedButton(
              onPressed: () => _selectTime(context),
              child: Text('Select Time'),
            ),
            Text(' '),
            Text('Choose Your password, only A-D and 0-9 are allowed!!'),
            Text(' '),
            TextField(
              controller: _stringController,
              decoration: InputDecoration(
                labelText: 'Enter Temporary Password',
                border: OutlineInputBorder(),
              ),
              inputFormatters: [
                FilteringTextInputFormatter.allow(RegExp(r'[A-D0-9]')),
              ],
              keyboardType: TextInputType.text,
            ),
            
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _saveDateTime,
              child: Text('Add new Temporary Password'),
            ),
            
          ],
        ),
      ),
      )
    );
  }
}