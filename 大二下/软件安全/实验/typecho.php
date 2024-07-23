/*typecho.php*/
<?php
class Typecho_Db{
	public function _construct($adapterName){
		$adapterName ='Typecho_Db_Adapter_'.$adapterName;
	}
}

class Typecho_Feed{
	private $item;
	public function _toString(){
		$this->item['author']->screenName;
	}
}

class Typecho_Request{
	private $_params = array();
	private $_filter = array();
	public function __get($key){
	return $this->get($key);
	}
	public function get($key,$default = NULL)
	{
		switch(true){
			case isset($this->_params[$key]):
				$value =$this->_params[$key];
				break;
			default:
				$value =$default;
				break;
		}
		$value =!is_array($value)&& strlen($value)>0? $value:$default;
		return $this->_applyFilter($value);
	}
	
	private function _applyFilter($value)
	{
		if ($this->_filter){
			foreach ($this->_filter as $filter){
				$value = is_array($value)? array_map($filter,$value):
				call_user_func($filter, $value);
			}
			$this->_filter = array();
		}
		return $value;
	}
}
$config=unserialize(base64_decode($_GET['__typecho_config']));
$db=new Typecho_Db($config['adapter']);
?>

