// 启动提交钩子（Start Commit Hook）脚本。  
// 将当前目录中的“MessageInfo.txt”文件内容填入“提交对话框”的日志信息中。  
  
var args = WScript.Arguments; // 钩子脚本被调用时，由Tortoisegit传入的参数  
var list = args(0); // 提交列表临时文件路径  
var message = args(1); // 日志消息临时文件路径  
var cwd = args(2); // 脚本执行的当前工作目录路径  
  
// call exe
var objShell = new ActiveXObject("wscript.shell");  
objShell.run(".\\toolBin\\ToolForGitCommit.exe", 1, true); // wait for result

// 使用FSO在当前工作目录中查找是否存在“readme.txt”文件  
var fso = new ActiveXObject('Scripting.FileSystemObject');  
var readme = cwd + '//toolBin//MessageInfo.txt';  
if (fso.FileExists(readme)) {  
    // 使用当前系统默认的编码方式(ANSI)读取文本文件  
    var ts = fso.OpenTextFile(readme, 1, false);  
    var text = ts.ReadAll();  
    ts.Close();  
  
    // 使用ADO Stream对象重新输出utf-8编码的文件，覆盖日志消息文件  
    // Tortoisegit将从消息文件中以utf-8编码读出消息，并填入提交对话框  
    var stream = new ActiveXObject('Adodb.Stream');  
    stream.Mode = 3; // read/write  
    stream.Open();  
    stream.Type = 2; // text  
    stream.Charset = 'utf-8';  
    stream.WriteText(text);  
    stream.SaveToFile(message, 2); // overwrite  
    stream.Close();  
}  